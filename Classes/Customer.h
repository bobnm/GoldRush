class Customer {
public:
	Customer();

	const Item& getNeedItem() const;
	int getMoney() const { return mMoney; }



private:
	int mMoney;
};

