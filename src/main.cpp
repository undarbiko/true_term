#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Tree.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include "nlohmann/json.hpp"
#include "FunnyLogger.h"

//https://github.com/IngwiePhoenix/FLTK/tree/master/examples
//https://www.fltk.org/articles.php?L415+I20+T+P1+Qresize
//https://github.com/nlohmann/json

using nlohmann::json;

Fl_Tabs *tabs = 0;
Fl_Tree *tree = 0;
Fl_Group *grpTree = 0;

void TreeCallback(Fl_Widget *w, void *data) {
  Fl_Tree *tree = (Fl_Tree*)w;
  Fl_Tree_Item *item = (Fl_Tree_Item*)tree->callback_item();
  if ( ! item ) return;
  switch ( tree->callback_reason() ) {
    case FL_TREE_REASON_SELECTED: {
      char pathname[256];
      tree->item_pathname(pathname, sizeof(pathname), item);
      FunnyLogger::log("TreeCallback: Item selected='%s', Full pathname='%s'\n", item->label(), pathname);
      break;
    }
    case FL_TREE_REASON_DESELECTED:
      FunnyLogger::log("TreeCallback: Item '%s' deselected\n", item->label());
      break;
    case FL_TREE_REASON_OPENED:
      FunnyLogger::log("TreeCallback: Item '%s' opened\n", item->label());
      break;
    case FL_TREE_REASON_CLOSED:
      FunnyLogger::log("TreeCallback: Item '%s' closed\n", item->label());
      break;
#if FLTK_ABI_VERSION >= 10301
    // To enable this callback, use tree->item_reselect_mode(FL_TREE_SELECTABLE_ALWAYS);
    case FL_TREE_REASON_RESELECTED:
      // fprintf(stderr, "TreeCallback: Item '%s' reselected\n", item->label());
      break;
#endif
    default:
      break;
  }
}

int main(int argc, char **argv) {
  std::string argv_str(argv[0]);
  std::string base = argv_str.substr(0, argv_str.find_last_of("\\"));
  FunnyLogger::setLogFile(base + "\\log.txt");
  FunnyLogger::log("Execution log started\n");
  json j = json::parse("{ \"happy\": true, \"pi\": 3.141 }");
  FunnyLogger::log("%s\n", j.dump(4).c_str());
  FunnyLogger::log("%s\n", j.find("happy").value().dump().c_str());
  Fl::scheme("gtk+");
  Fl_Double_Window *win = new Fl_Double_Window(500, 500, "Simple Testing");
  win->begin();
  {
    // grpTree = new Fl_Group(5, 5, 145, win->h()-20);
    // grpTree->begin();
    // {
    //   // Create the tree
    //   tree = new Fl_Tree(10, 10, 140, win->h()-20);
    //   tree->begin();
    //   {
    //     tree->showroot(0);				// don't show root of tree
    //     tree->callback(TreeCallback);		// setup a callback for the tree

    //     // Add some items
    //     tree->add("Flintstones/Fred/Harry");
    //     tree->add("Flintstones/Wilma");
    //     tree->add("Flintstones/Pebbles");
    //     tree->add("Simpsons/Homer");
    //     tree->add("Simpsons/Marge");
    //     tree->add("Simpsons/Bart");
    //     tree->add("Simpsons/Lisa");
    //     tree->add("Pathnames/\\/bin");		// front slashes
    //     tree->add("Pathnames/\\/usr\\/sbin");
    //     tree->add("Pathnames/C:\\\\Program Files");	// backslashes
    //     tree->add("Pathnames/C:\\\\Documents and Settings");

    //     // Start with some items closed
    //     tree->close("Flintstones/Fred");
    //     tree->close("Simpsons");
    //     tree->close("Pathnames");
    //   }
    //   tree->end();
    // }
    // grpTree->end();
    // grpTree->resizable(0);// no resizing

      tree = new Fl_Tree(10, 10, 140, 480);
      tree->begin();
      {
        tree->showroot(0);				// don't show root of tree
        tree->callback(TreeCallback);		// setup a callback for the tree

        // Add some items
        tree->add("Flintstones/Fred/Harry");
        tree->add("Flintstones/Wilma");
        tree->add("Flintstones/Pebbles");
        tree->add("Simpsons/Homer");
        tree->add("Simpsons/Marge");
        tree->add("Simpsons/Bart");
        tree->add("Simpsons/Lisa");
        tree->add("Pathnames/\\/bin");		// front slashes
        tree->add("Pathnames/\\/usr\\/sbin");
        tree->add("Pathnames/C:\\\\Program Files");	// backslashes
        tree->add("Pathnames/C:\\\\Documents and Settings");

        // Start with some items closed
        tree->close("Flintstones/Fred");
        tree->close("Simpsons");
        tree->close("Pathnames");
      }
      tree->end();

    tabs = new Fl_Tabs(160, 10, 330, 480);
    {
      // Aaa tab
      Fl_Group *aaa = new Fl_Group(170, 35, 320, 470, "Tab A");
      {
            // Fl_Button *b1 = new Fl_Button(50, 60,90,25,"Button A1"); b1->color(88+1);
            // Fl_Button *b2 = new Fl_Button(50, 90,90,25,"Button A2"); b2->color(88+2);
            // Fl_Button *b3 = new Fl_Button(50,120,90,25,"Button A3"); b3->color(88+3);
      }
      aaa->end();
      // Bbb tab
      Fl_Group *bbb = new Fl_Group(170, 35, 320, 470, "Tab B");
      {
        // Fl_Button *b1 = new Fl_Button( 50,60,90,25,"Button B1"); b1->color(88+1);
        // Fl_Button *b2 = new Fl_Button(150,60,90,25,"Button B2"); b2->color(88+3);
        // Fl_Button *b3 = new Fl_Button(250,60,90,25,"Button B3"); b3->color(88+5);
        // Fl_Button *b4 = new Fl_Button( 50,90,90,25,"Button B4"); b4->color(88+2);
        // Fl_Button *b5 = new Fl_Button(150,90,90,25,"Button B5"); b5->color(88+4);
        // Fl_Button *b6 = new Fl_Button(250,90,90,25,"Button B6"); b6->color(88+6);
      }
      bbb->end();
    }
    tabs->end();
  }
  win->end();
  win->resizable(tabs);
  win->size_range(win->w(), win->h(), 0, 0);
  win->show(argc, argv);
  int result = Fl::run();
  FunnyLogger::log("Terminated\n");
  return result;
}