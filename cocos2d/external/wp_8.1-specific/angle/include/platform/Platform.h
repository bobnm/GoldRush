//
// Copyright (c) 2015 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Platform.h: The public interface ANGLE exposes to the API layer, for
//   doing platform-specific tasks like gathering data, or for tracing.

#ifndef ANGLE_PLATFORM_H
#define ANGLE_PLATFORM_H

#include <stdint.h>

#include "../export.h"

namespace angle
{

class Platform
{
  public:

    ANGLE_EXPORT static void initialize(Platform*);
    ANGLE_EXPORT static void shutdown();
    ANGLE_EXPORT static Platform *current();

    // Tracing --------

    typedef uint64_t TraceEventHandle;

    // Add a trace event to the platform tracing system. Depending on the actual
    // enabled state, this event may be recorded or dropped.
    // - phase specifies the type of event:
    //   - BEGIN ('B'): Marks the beginning of a scoped event.
    //   - END ('E'): Marks the end of a scoped event.
    //   - COMPLETE ('X'): Marks the beginning of a scoped event, but doesn't
    //     need a matching END event. Instead, at the end of the scope,
    //     updateTraceEventDuration() must be called with the TraceEventHandle
    //     returned from addTraceEvent().
    //   - INSTANT ('I'): Standalone, instantaneous event.
    //   - START ('S'): Marks the beginning of an asynchronous event (the end
    //     event can occur in a different scope or thread). The id parameter is
    //     used to match START/FINISH pairs.
    //   - FINISH ('F'): Marks the end of an asynchronous event.
    //   - COUNTER ('C'): Used to trace integer quantities that change over
    //     time. The argument values are expected to be of type int.
    //   - METADATA ('M'): Reserved for internal use.
    // - categoryEnabled is the pointer returned by getTraceCategoryEnabledFlag.
    // - name is the name of the event. Also used to match BEGIN/END and
    //   START/FINISH pairs.
    // - id optionally allows events of the same name to be distinguished from
    //   each other. For example, to trace the consutruction and destruction of
    //   objects, specify the pointer as the id parameter.
    // - numArgs specifies the number of elements in argNames, argTypes, and
    //   argValues.
    // - argNames is the array of argument names. Use long-lived literal strings
    //   or specify the COPY flag.
    // - argTypes is the array of argument types:
    //   - BOOL (1): bool
    //   - UINT (2): unsigned long long
    //   - INT (3): long long
    //   - DOUBLE (4): double
    //   - POINTER (5): void*
    //   - STRING (6): char* (long-lived null-terminated char* string)
    //   - COPY_STRING (7): char* (temporary null-terminated char* string)
    //   - CONVERTABLE (8): WebConvertableToTraceFormat
    // - argValues is the array of argument values. Each value is the unsigned
    //   long long member of a union of all supported types.
    // - flags can be 0 or one or more of the following, ORed together:
    //   - COPY (0x1): treat all strings (name, argNames and argValues of type
    //     string) as temporary so that they will be copied by addTraceEvent.
    //   - HAS_ID (0x2): use the id argument to uniquely identify the event for
    //     matching with other events of the same name.
    //   - MANGLE_ID (0x4): specify this flag if the id parameter is the value
    //     of a pointer.
    virtual TraceEventHandle addTraceEvent(char phase,
                                           const unsigned char *categoryEnabledFlag,
                                           const char *name,
                                           unsigned long long id,
                                           double timestamp,
                                           int numArgs,
                                           const char **argNames,
                                           const unsigned char *argTypes,
                                           const unsigned long long *argValues,
                                           unsigned char flags)
    {
        return 0;
    }

    // Set the duration field of a COMPLETE trace event.
    virtual void updateTraceEventDuration(const unsigned char* categoryEnabledFlag, const char* name, TraceEventHandle) { }

    // Callbacks for reporting histogram data.
    // CustomCounts histogram has exponential bucket sizes, so that min=1, max=1000000, bucketCount=50 would do.
    virtual void histogramCustomCounts(const char* name, int sample, int min, int max, int bucketCount) { }
    // Enumeration histogram buckets are linear, boundaryValue should be larger than any possible sample value.
    virtual void histogramEnumeration(const char* name, int sample, int boundaryValue) { }
    // Unlike enumeration histograms, sparse histograms only allocate memory for non-empty buckets.
    virtual void histogramSparse(const char* name, int sample) { }

  protected:
    virtual ~Platform() { }
};

}

#endif // ANGLE_PLATFORM_H
