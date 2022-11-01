#include "corvo_xml.hpp"
#include <sstream>

using std::stringstream;

XmlElmt::XmlElmt(const string& tag, const string& id) : tag{tag} {
  this->properties.push_back(Props{"id", id});
}

string XmlElmt::gen_xml() const {
  stringstream ss;
  ss << '<' << this->tag;
  for (const Props& p : this->properties)
    ss << ' ' << p.key << "=\"" << p.value << '\"';
  ss << '>';
  ss << this->inner_text;
  for (const shared_ptr<XmlElmt>& child : this->childs)
    ss << child->gen_xml();
  ss << "</" << this->tag << '>';
  return ss.str();
}

void XmlElmt::add_props(const Props& prop) {
  this->properties.push_back(prop);
}

void XmlElmt::add_props(const string& key, const string& value) {
  this->properties.push_back(Props{key, value});
}

void XmlElmt::add_child(shared_ptr<XmlElmt> child) {
  this->childs.push_back(child);
}