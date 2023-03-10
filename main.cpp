#include "web_server/request.h"
#include "web_server/response.h"
#include "web_server/server.h"

#include <iostream>

auto main() -> int {
    // create new htpp::Server() on port 8080
    http::Server *app = new http::Server(8080);

    // set html, static files path for resources
    http::response::set_html_path("public/html/");
    http::response::set_static_path("public/static/");

    // create a route at /index
    app->add_route("/index", [](const std::string &request) -> std::string {
        // check if the request is a get request
        if (request == http::request::get) {
            // return the contents of the index.html file
            return http::response::read_file("index.html");
        }
        return "FAILURE";
    });

    // create a route at /about
    app->add_route("/about", [](const std::string &request) -> std::string {
        // check if it is a get request
        if (request == http::request::get) {
            // return the contents of the about.html file
            return http::response::read_file("about.html");
        }
        return "FAILURE";
    });

    // run and delete the app
    app->run();
    delete app;

    return 0;
}
