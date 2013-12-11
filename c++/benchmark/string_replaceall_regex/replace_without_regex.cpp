#include <hayai.hpp>
#include <string>
#include <iostream>

using std::string;

void replaceAll(std::string& str, const std::string& oldStr,
    const std::string& newStr) {
  size_t pos = 0;
  while ((pos = str.find(oldStr, pos)) != std::string::npos) {
    str.replace(pos, oldStr.length(), newStr);
    pos += newStr.length();
  }
}

BENCHMARK(Sql, ReplaceAll, 10, 1000)
{
    string sql = "select * from aa where a_param like :a_param and b_param = :b_param";
    replaceAll(sql, ":a_param", "a_value");
    replaceAll(sql, ":b_param", "b_value");
    //std::cout << sql << std::endl;
}

