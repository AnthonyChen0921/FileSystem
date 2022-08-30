// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../SharedCode/AbstractFileFactory.h"
#include "../../SharedCode/AbstractFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/ImageFile.h"
#include "../../SharedCode/PasswordProxy.h"
#include "../../SharedCode/BasicDisplayVisitor.h"
#include "../../SharedCode/CommandPrompt.h"
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/LSCommand.h"
#include "../../SharedCode/RemoveCommand.h"
#include "../../SharedCode/DisplayCommand.h"
#include "../../SharedCode/CatCommand.h"
#include "../../SharedCode/MacroCommand.h"
#include "../../SharedCode/CopyCommand.h"



using namespace std;

int main()
{
	
	// test imageFile
	vector<char> a = { 'X',' ','X',' ' ,'X',' ' ,'X',' ', 'X', '3' };
	ImageFile imageF("ds.img");
	imageF.write(a);

	SimpleFileSystem filesys;
	SimpleFileFactory filefactory;
	auto p1 = filefactory.createFile("Hello.txt");
	//auto p2 = filefactory.createFile("ds.img");
	auto p3 = filefactory.createFile("Halo.txt");
	//auto p4 = filefactory.createFile("Halo.img");
	filesys.addFile("Hello.txt", p1);
	filesys.addFile("ds.img", &imageF);
	filesys.addFile("Halo.txt", p3);
	//filesys.addFile("Halo.img", p4);
	


	//initialize command
	TouchCommand touch(&filesys, &filefactory);
	LSCommand ls(&filesys);
	RemoveCommand rm(&filesys);
	DisplayCommand ds(&filesys);
	CatCommand ct(&filesys);
	CopyCommand cpc(&filesys);
	MacroCommand mc(&filesys);
	auto mcp = &mc;
	//initialize strategy
	RenameParsingStrategy* rps = new RenameParsingStrategy();
	mcp->setParseStrategy(rps);
	mcp->addCommand(&cpc);
	mcp->addCommand(&rm);

	CommandPrompt cp;
	cp.addCommand("touch", &touch);
	cp.addCommand("ls", &ls);
	cp.addCommand("rm", &rm);
	cp.addCommand("ds", &ds);
	cp.addCommand("cat", &ct);
	cp.addCommand("rn", &mc);
	cp.addCommand("cp", &cpc);
	cp.run();

	return 0;
}

