/**
 * @file      Object.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2021, Sergey Baigudin, Baigudin Software
 */
#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include "api.Object.hpp"
#include "ObjectAllocator.hpp"

namespace eoos
{
    
/**
 * @class Object<A>
 * @brief Root class of the class hierarchy.
 *
 * @tparam A Heap memory allocator class.
 */
template <class A = Allocator>
class Object : public ObjectAllocator<A>, public api::Object
{

public:

    /**
     * @brief Constructor.
     */
    Object() :
        isConstructed_ (true){
    }

    /**
     * @brief Destructor.
     */
    virtual ~Object()
    {
        isConstructed_ = false;
    }
    
    /**
     * @brief Copy constructor.
     *
     * @param obj Reference to a source object.
     */
    Object(const Object& obj) :
        isConstructed_(obj.isConstructed_){
    }
    
    
    /**
     * @brief Copy assignment operator.
     *
     * @param obj Reference to a source object.
     * @return Reference to this object.
     */       
    Object& operator=(const Object& obj)
    {
        if( this != &obj && isConstructed() )
        {
            isConstructed_ = obj.isConstructed_;
        }
        return *this;
    }    

    #if EOOS_CPP_STANDARD >= 2011

    /**
     * @brief Move constructor.
     *
     * @param obj Right reference to a source object.     
     */       
    Object(Object&& obj) noexcept :
        isConstructed_(obj.isConstructed_){
        obj.setConstructed(false);
    }   
    
    /**
     * @brief Move assignment operator.
     *
     * @param obj Right reference to a source object.
     * @return Reference to this object.
     */
    Object& operator=(Object&& obj) noexcept
    {
        if( this != &obj && isConstructed() )
        {
            isConstructed_ = obj.isConstructed_;
            obj.setConstructed(false);
        }
        return *this;
    }        
    
    #endif // EOOS_CPP_STANDARD >= 2011

    /**
     * @copydoc eoos::api::Object::isConstructed()
     */
    virtual bool_t isConstructed() const
    {
        return isConstructed_;
    }
    
    /**
     * @brief Tests if an object has been constructed.
     *
     * @param obj Object to be tested.
     * @return True if object has been constructed successfully.
     */
    static bool_t isConstructed(api::Object* const obj)
    {
        bool_t isConstructed = false;
        if(obj != NULLPTR)
        {
            isConstructed = obj->isConstructed();
        }
        return isConstructed;
    }    

protected:

    /**
     * @brief Sets the object constructed flag.
     *
     * @param flag A new constructed flag.
     */
    void setConstructed(bool_t const flag)
    {
        if( isConstructed_ == true )
        {
            isConstructed_ = flag;
        }
    }

private:

    /**
     * @brief This object constructed flag.
     */
    bool_t isConstructed_;

};
  
} // namespace eoos

#endif // OBJECT_HPP_
