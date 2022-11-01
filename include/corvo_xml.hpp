#ifndef CORVO_XML_HPP_
#define CORVO_XML_HPP_

#include <string>
#include <vector>
#include <memory>

using std::string;
using std::vector;
using std::shared_ptr;

struct Props {
  string key;
  string value;
};

class XmlElmt {
public:
  XmlElmt(const string& tag, const string& id);
  const string tag;
  string gen_xml() const;
  void add_props(const Props& prop);
  void add_props(const string& key, const string& value);
  void add_child(shared_ptr<XmlElmt> child);
  shared_ptr<XmlElmt>& get_child_by_id(string id);
protected:
  string inner_text;
private:
  vector<Props> properties;
  vector<shared_ptr<XmlElmt>> childs;
};

#endif // CORVO_XML_HPP_