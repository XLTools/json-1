//  :copyright: (c) 2016 The Regents of the University of California.
//  :license: MIT, see LICENSE.md for more details.
/**
 *  \addtogroup JSON
 *  \brief Write types to stream.
 */

#include "json/detail/ieee754.hpp"
#include "json/detail/string.hpp"
#include "json/detail/write.hpp"


namespace json
{
namespace detail
{
// FUNCTIONS
// ---------


/** \brief Write null value.
 */
std::ostream & write(std::ostream &stream,
    const std::nullptr_t nullp)
{
    stream.write("null", 4);
    return stream;
}


/** \brief Write bool.
 */
std::ostream & write(std::ostream &stream,
    const bool boolean)
{
    if (boolean) {
        stream.write("true", 4);
    } else {
        stream.write("false", 5);
    }
}


/** \brief Write string.
 */
std::ostream & write(std::ostream &stream,
    const std::string &string)
{
    auto escaped = escape(string);
    stream.write(escaped.data(), escaped.size());

    return stream;
}


/** \brief Write character.
 */
std::ostream & write(std::ostream &stream,
    const char character)
{
    stream.put('"');
    stream.put(character);
    stream.put('"');

    return stream;
}


/** \brief Write character.
 */
std::ostream & write(std::ostream &stream,
    const unsigned char character)
{
    write(stream, static_cast<char>(character));
}


/** \brief Write float.
 */
std::ostream & write(std::ostream &stream,
    const float number)
{
    write(stream, static_cast<double>(number));
}


/** \brief Write double.
 */
std::ostream & write(std::ostream &stream,
    const double number)
{
    if (!isFinite(number)) {
        // IEEE754 special numbers, technically not part of spec.
        if (isNan(number)) {
            stream.write("NaN", 3);
        } else if (isInfinity(number)) {
            stream.write("inf", 3);
        } else {
            stream.write("-inf", 4);
        }
    } else if (isZero(number)) {
        if (isPositive(number)) {
            stream.write("0.0", 3);
        } else {
            stream.write("-0.0", 4);
        }
    } else {
        // TODO: enhance perfomance here
        write(stream, std::to_string(number));
    }

    return stream;
}


/** \brief Write integer.
 */
std::ostream & write(std::ostream &stream,
    const int16_t number)
{
    // TODO: enhance perfomance here
    write(stream, std::to_string(number));

    return stream;
}


/** \brief Write integer.
 */
std::ostream & write(std::ostream &stream,
    const uint16_t number)
{
    // TODO: enhance perfomance here
    write(stream, std::to_string(number));

    return stream;
}


/** \brief Write integer.
 */
std::ostream & write(std::ostream &stream,
    const int32_t number)
{
    // TODO: enhance perfomance here
    write(stream, std::to_string(number));

    return stream;
}


/** \brief Write integer.
 */
std::ostream & write(std::ostream &stream,
    const uint32_t number)
{
    // TODO: enhance perfomance here
    write(stream, std::to_string(number));

    return stream;
}


/** \brief Write integer.
 */
std::ostream & write(std::ostream &stream,
    const int64_t number)
{
    // TODO: enhance perfomance here
    write(stream, std::to_string(number));

    return stream;
}


/** \brief Write integer.
 */
std::ostream & write(std::ostream &stream,
    const uint64_t number)
{
    // TODO: enhance perfomance here
    write(stream, std::to_string(number));

    return stream;
}

}   /* detail */
}   /* json */