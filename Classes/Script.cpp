namespace { 
void Init()
{
	Director::getInstance()->runWithScene(HelloWorld::createScene());
}

}

Script::Script()
{
}

void Script::init()
{
	Init();
	wait
}

