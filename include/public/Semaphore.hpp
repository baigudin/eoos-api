/**
 * Semaphore class.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef SEMAPHORE_HPP_
#define SEMAPHORE_HPP_

#include "Object.hpp"
#include "api.Semaphore.hpp"
#include "System.hpp"

namespace eoos
{
    class Semaphore : public Object<>, public api::Semaphore
    {
        typedef Semaphore Self;
        typedef ::eoos::Object<> Parent;

    public:

        /**
         * Constructor.
         *
         * @param permits - the initial number of permits available.
         */
        Semaphore(const int32_t permits) : Parent(),
            semaphore_ (NULLPTR){
            bool_t const isConstructed = construct(permits, NULLPTR);
            setConstructed( isConstructed );
        }

        /**
         * Constructor.
         *
         * @param permits - the initial number of permits available.
         * @param isFair  - true if this semaphore will guarantee FIFO granting of permits under contention.
         */
        Semaphore(const int32_t permits, const bool_t isFair) : Parent(),
            semaphore_ (NULLPTR){
            bool_t const isConstructed = construct(permits, &isFair);
            setConstructed( isConstructed );
        }

        /**
         * Destructor.
         */
        virtual ~Semaphore()
        {
            delete semaphore_;
        }

        /**
         * Tests if this object has been constructed.
         *
         * @return true if object has been constructed successfully.
         */
        virtual bool_t isConstructed() const
        {
            return Parent::isConstructed();
        }

        /**
         * Acquires one permit from this semaphore.
         *
         * @return true if the semaphore is acquired successfully.
         */
        virtual bool_t acquire()
        {
            if( Self::isConstructed() )
            {
                return semaphore_->acquire();
            }
            else
            {
                return false;
            }
        }

        /**
         * Acquires the given number of permits from this semaphore.
         *
         * @param permits - the number of permits to acquire.
         * @return true if the semaphore is acquired successfully.
         */
        virtual bool_t acquire(int32_t const permits)
        {
            if( Self::isConstructed() )
            {
                return semaphore_->acquire(permits);
            }
            else
            {
                return false;
            }
        }

        /**
         * Releases one permit.
         */
        virtual void release()
        {
            if( Self::isConstructed() )
            {
                semaphore_->release();
            }
        }

        /**
         * Releases the given number of permits.
         *
         * @param permits - the number of permits to release.
         */
        virtual void release(int32_t const permits)
        {
            if( Self::isConstructed() )
            {
                semaphore_->release(permits);
            }
        }

        /**
         * Tests if this semaphore is fair.
         *
         * @return true if this semaphore has fairness set true.
         */
        virtual bool_t isFair() const
        {
            if( Self::isConstructed() )
            {
                return semaphore_->isFair();
            }
            else
            {
                return false;
            }
        }

        /**
         * Tests if this resource is blocked.
         *
         * @return true if this resource is blocked.
         */
        virtual bool_t isBlocked() const
        {
            if( Self::isConstructed() )
            {
                return semaphore_->isBlocked();
            }
            else
            {
                return false;
            }
        }

    private:

        /**
         * Constructor.
         *
         * @param permits - the initial number of permits available.
         * @param isFair  - true if this semaphore will guarantee FIFO granting of permits under contention.
         * @return true if object has been constructed successfully.
         */
        bool_t construct(const int32_t permits, const bool_t* const isFair)
        {
            bool_t res = Self::isConstructed();
            if( res == true )
            {
                return false;
            }
            if( isFair == NULLPTR )
            {
                semaphore_ = System::call().createSemaphore(permits, false);
            }
            else
            {
                semaphore_ = System::call().createSemaphore(permits, *isFair);
            }
            return semaphore_ != NULLPTR ? semaphore_->isConstructed() : false;
        }

        /**
         * Copy constructor.
         *
         * @param obj - reference to source object.
         */
        Semaphore(const Semaphore& obj);

        /**
         * Assignment operator.
         *
         * @param obj - reference to source object.
         * @return reference to this object.
         */
        Semaphore& operator=(const Semaphore& obj);

        /**
         * System semaphore interface.
         */
        api::Semaphore* semaphore_;

    };
}
#endif // SEMAPHORE_HPP_