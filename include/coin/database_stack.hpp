/*
 * Copyright (c) 2013-2015 John Connor (BM-NC49AxAjcqVcF5jNPu85Rb8MJ2d9JqZt)
 *
 * This file is part of vanillacoin.
 *
 * vanillacoin is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef COIN_DATABASE_STACK_HPP
#define COIN_DATABASE_STACK_HPP

#define USE_DATABASE_STACK 0

#include <cstdint>
#include <string>

#if (defined USE_DATABASE_STACK && USE_DATABASE_STACK)
#include <database/stack.hpp>
#endif // USE_DATABASE_STACK

namespace coin {

    /**
     * Implements a database::stack subclass.
     */
#if (defined USE_DATABASE_STACK && USE_DATABASE_STACK)
    class database_stack : public database::stack
#else
    class database_stack
#endif // USE_DATABASE_STACK
    {
        public:
        
            /**
             * Starts the stack.
             * @param port The port.
             * @param is_client If true we are a client node.
             */
            void start(const std::uint16_t & port, const bool & is_client);
            
            /**
             * Stops the stack.
             */
            void stop();
        
        private:
        
            /**
             * Called when a search result is received.
             * @param transaction_id The transaction id.
             * @param query The query.
             */
            virtual void on_find(
                const std::uint16_t & transaction_id,
                const std::string & query
            );
        
            /**
             * Called when a udp packet doesn't match the protocol fingerprint.
             * @param addr The address.
             * @param port The port.
             * @param buf The buffer.
             * @param len The length.
             */
            virtual void on_udp_receive(
                const char * addr, const std::uint16_t & port, const char * buf,
                const std::size_t & len
            );

            /**
             * Called when a broadcast message is received.
             * @param addr The address.
             * @param port The port.
             * @param buf The buffer.
             * @param len The length.
             */
            virtual void on_broadcast(
                const char * addr, const std::uint16_t & port,
                const char * buf, const std::size_t & len
            );
        
        protected:
        
            // ...
    };
    
} // namespace coin

#endif // COIN_DATABASE_STACK_HPP