#include <gtest/gtest.h>
#include "corvo_xml.hpp"


TEST(XmlElmtTest, ClassInit) {
  XmlElmt t{"svg", "svg_1"};
  EXPECT_EQ(t.tag, "svg");
  EXPECT_EQ(t.gen_xml(), "<svg id=\"svg_1\"></svg>");
}

TEST(XmlElmtTest, Childs) {
  XmlElmt t{"svg", "svg_1"};
  shared_ptr<XmlElmt> c{new XmlElmt{"rect", "rect_1"}};
  c->add_props(Props{"cx", "56"});
  t.add_child(c);
  EXPECT_EQ(t.gen_xml(), "<svg id=\"svg_1\"><rect id=\"rect_1\" cx=\"56\"></rect></svg>");
}
