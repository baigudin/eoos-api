/**
 * @file      api.IllegalValue.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2021, Sergey Baigudin, Baigudin Software
 */
#ifndef API_ILLEGAL_VALUE_HPP_
#define API_ILLEGAL_VALUE_HPP_

#include "api.Object.hpp"

namespace eoos
{
namespace api
{

/**
 * @class IllegalValue<T>
 * @brief Illegal value interface.
 *
 * @tparam T Data type of value.
 */
template <typename T>
class IllegalValue : public Object
{

public:

    /**
     * @brief Destructor.
     */
    virtual ~IllegalValue() = 0;

    /**
     * @brief Returns illegal element which will be returned as error value.
     *
     * @return Illegal element.
     */
    virtual T& getIllegal() const = 0;

    /**
     * @brief Sets illegal element which will be returned as error value.
     *
     * @note A passed value must be copied to an internal data structure of
     * a realizing class by calling a copy constructor so that the variable
     * might be invalidated after the function called.
     *
     * @param value An illegal value.
     */
    virtual void setIllegal(const T& value) = 0;

    /**
     * @brief Tests if given value is an illegal.
     *
     * @param value A testing value.
     * @return True if value is an illegal.
     */
    virtual bool_t isIllegal(const T& value) const = 0;

};

template <typename T>
inline IllegalValue<T>::~IllegalValue() {}

} // namespace api
} // namespace eoos
#endif // API_ILLEGAL_VALUE_HPP_
