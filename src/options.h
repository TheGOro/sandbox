/* 
 * File:   options.h
 * Author: GOro
 *
 * Created on 2013. október 27., 0:28
 */

#ifndef OPTIONS_H
#define	OPTIONS_H

#include <map>
#include <string>
#include <ostream>
#include <istream>
#include <algorithm>
#include "variant.h"

namespace sandbox {
/*! Option store class */
class Options {
    private:
        typedef std::map<std::string, Variant> OptionStore;
        typedef std::pair<std::string, Variant> OptionPair;
        OptionStore store;
        friend inline std::ostream& operator << (std::ostream&, Options& options);
        friend inline std::istream& operator >> (std::istream&, Options& options);
    public:
        typedef std::map<std::string, Variant>::size_type size_type;
        inline Variant& operator [] (std::string const& key);
        inline void persist() const;
        inline void persistAs(std::string const& filename) const;
        inline void clear();
        inline size_type count(std::string const& key) const;
        inline bool empty() const;
        inline size_type size() const;
        inline void swap(Options& other);
};
    
/*!
    \brief Writes all data to a output stream.
 */
inline std::ostream& operator << (std::ostream& output, Options& options) {
    std::for_each(options.store.begin(), options.store.end(), [&output] (Options::OptionPair elem) { // algorithm's for_each+lambda, sweet!
        output << elem.first << '=' << elem.second << std::endl;
    });
    return output;
}

/*!
    \brief Reads key value pairs from an input stream.
     it's throws Options::invalid_format exception on misformatted input.
 */
inline std::istream& operator >> (std::istream& input, Options& options) {
    return input;
}

/*!
    \brief Operator to access a value via his key.
 */
inline Variant& Options::operator [](std::string const& key) {
    return store[key];
}

inline void Options::clear() {
    store.clear();
}

inline inline bool Options::empty() const {
    return store.empty();
}

inline Options::size_type Options::size() const {
    return store.size();
}

inline Options::size_type Options::count(std::string const& key) const {
    return store.count(key);
}

}
#endif	/* OPTIONS_H */

