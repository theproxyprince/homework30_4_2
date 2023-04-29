#include "cpr/cpr.h"
#include <iostream>

int main() {
    std::string a = "hello", headerText;
    cpr::Response response = cpr::Get(cpr::Url("https://httpbin.org/html"));
    if (response.status_code == 200) {
        std::cout << response.text << std::endl;
        headerText = response.text.substr(response.text.find("<h1>") + strlen("<h1>"),
                                          response.text.find("</h1>") - response.text.find("<h1>") - strlen("<h1>"));
        std::cout << "Header text: " << headerText << std::endl;
    } else {
        std::cout << "Status code: " << response.status_code << std::endl;
    }

}