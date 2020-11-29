//
// Created by hungr on 2020/11/22.
//

#ifndef XMLRO_XML_N_TREE_H
#define XMLRO_XML_N_TREE_H

#include <cstddef>
#include <tuple>
#include <type_traits>

namespace xml::detail {
    template <bool... B>
    class all_true {
        template <bool... C>
        struct all_true_impl;
    public:
        inline static constexpr bool value = std::is_same_v<all_true_impl<true, B...>, all_true_impl<B..., true>>;
    };
    template <bool... B>
    inline constexpr bool all_true_v = all_true<B...>::value;

    template <class T, class=void>
    struct has_attribute : std::false_type {};
    template <class T>
    struct has_attribute<T, std::void_t<typename T::attribute>> : std::true_type {};

    template <class T, class=void>
    struct has_children : std::false_type {};
    template <class T>
    struct has_children<T, std::void_t<typename T::children>> : std::true_type {};


    struct xml_text {
        using nodable = void;
    };

    template <class T>
    using is_xml_n_node = std::disjunction<std::conjunction<has_attribute<T>, has_children<T>>, std::is_same<T, xml_text>>;
    template <class T>
    inline constexpr bool is_xml_n_node_v = is_xml_n_node<T>::value;

    template <std::size_t N>
    struct xml_n_attribute {
        inline static constexpr std::size_t n = N;
    };

    template <std::size_t N, class... TChild>
    struct xml_n_node_list {
        static_assert(all_true_v<is_xml_n_node_v<TChild>...>, "given TChild is not xml_n_node (xml_n_node_list)");
        inline static constexpr std::size_t n = N;
        template <std::size_t I>
        using element_t = std::tuple_element_t<I, std::tuple<TChild...>>;
    };

    template <std::size_t N, std::size_t M, class... TChild>
    struct xml_n_element {
        static_assert(N == sizeof...(TChild), "given N is not equal to the number of TChild (xml_n_child)");
        using attribute = xml_n_attribute<M>;
        using children = xml_n_node_list<N, TChild...>;
        using nodable = std::enable_if_t<all_true_v<std::is_same_v<void, typename TChild::nodable>...>, void>;
    };
}

#endif //XMLRO_XML_N_TREE_H
