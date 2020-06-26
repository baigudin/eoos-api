/**
 * Hardware timer resource interface.
 *
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2020, Sergey Baigudin, Baigudin Software
 */
#ifndef API_TIMER_HPP_
#define API_TIMER_HPP_

#include "api.Object.hpp"

namespace eoos
{
    namespace api
    {
        class Timer : public Object
        {

        public:

            /**
             * Destructor.
             */
            virtual ~Timer(){}

            /**
             * Gets this timer counter.
             *
             * @return timer counter register value.
             */
            virtual int64_t getCount() const = 0;

            /**
             * Gets this timer period.
             *
             * @return timer period register value.
             */
            virtual int64_t getPeriod() const = 0;

            /**
             * Sets this timer counter.
             *
             * @param count - timer counter register value.
             */
            virtual void setCount(int64_t count) = 0;

            /**
             * Sets this timer period.
             *
             * @param us - timer period in microseconds, zero value sets a period to maximum value.
             */
            virtual void setPeriod(int64_t us=0) = 0;

            /**
             * Starts this timer count.
             */
            virtual void start() = 0;

            /**
             * Stops this timer count.
             */
            virtual void stop() = 0;

            /**
             * Returns this timer index.
             *
             * @return index of this timer, or -1 if an error has been occurred.
             */
            virtual int32_t getIndex() const = 0;

        };
    }
}
#endif // API_TIMER_HPP_