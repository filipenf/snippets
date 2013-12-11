#include <hayai.hpp>
#include <string>
#include <iostream>
#include <string.h>
#include <regex.h>
#include <stdexcept>

using std::string;
using std::runtime_error;

int rreplace (string &source, regex_t *re, const string &replacement)
{
    int MAX_GROUPS = 10;
    char *pos;
    int sub, so, n;
    regmatch_t groups [MAX_GROUPS];
    if (regexec (re, source.c_str(), MAX_GROUPS, groups, 0))
        throw runtime_error("Não foi possível executar expressão regular");
    int offset = 0;
    for (int g = 0; g < MAX_GROUPS; g++) {
        if (groups[g].rm_so == (size_t)-1)
            break;  // No more groups
        groups[g].rm_so += offset;
        groups[g].rm_eo += offset;
        int groupLen = groups[g].rm_eo - groups[g].rm_so;
        source.erase(groups[g].rm_so, groupLen);
        source.insert(groups[g].rm_so, replacement);
        offset += replacement.length() - groupLen;
    }
    return 0;
}

void regexReplace(std::string& str, const std::string &oldStr, const std::string &newStr) {
    regex_t re;
    if (regcomp (&re, oldStr.c_str(), REG_ICASE))
        throw runtime_error("Erro compilando regex");
    rreplace(str, &re, newStr.c_str());
}

BENCHMARK(Sql, regexReplace, 10, 1000)
{
    string sql = "select * from aa where a_param like :a_param and b_param = :b_param";
    regexReplace(sql, ":a_param", "a_value");
    regexReplace(sql, ":b_param", "b_value");
//    std::cout << sql << std::endl;
}

