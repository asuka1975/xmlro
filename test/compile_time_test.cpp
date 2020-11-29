//
// Created by hungr on 2020/11/27.
//
#include "xmlro/detail/xml_n_tree.h"

namespace {
    void test_func_xml_n_element() {
        xml::detail::xml_n_element<1, 2, xml::detail::xml_text> x1;
        //xml::detail::xml_n_element<2, 2, xml::detail::xml_text> x2;
        //xml::detail::xml_n_element<2, 1, xml::detail::xml_text> x3;
        xml::detail::xml_n_element<2, 2, xml::detail::xml_text, xml::detail::xml_n_element<1, 1, xml::detail::xml_text>> x4;
        //xml::detail::xml_n_element<2, 2, xml::detail::xml_text, xml::detail::xml_n_element<2, 1, xml::detail::xml_text>> x5;

    }
}