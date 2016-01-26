#ifndef JSON_EXTENSION_H
#define JSON_EXTENSION_H

#include <gloox/tag.h>
#include <gloox/stanzaextension.h>
#include <string>

namespace gloox
{

    class Tag;

    class GLOOX_API JsonExtension : public StanzaExtension
    {
        public:

            JsonExtension( const std::string& json );

            /**
             * Constructs a new Carbons instance from the given tag.
             * @param tag The Tag to create the Carbons instance from.
             */
            JsonExtension( const Tag* tag = 0 );

            /**
             * Virtual destructor.
             */
            virtual ~JsonExtension();

            // reimplemented from StanzaExtension
            virtual const std::string& filterString() const;

            // reimplemented from StanzaExtension
            virtual StanzaExtension* newInstance( const Tag* tag ) const
            {
                return new JsonExtension( tag );
            }


            // reimplemented from StanzaExtension
            Tag* tag() const;

            // reimplemented from StanzaExtension
            virtual StanzaExtension* clone() const
            {
                return new JsonExtension( *this );
            }


        private:
            std::string m_json;
    };
}

#endif
