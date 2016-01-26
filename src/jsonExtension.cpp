#include "jsonExtension.h"
#include <gloox/util.h>

namespace gloox
{

    JsonExtension::JsonExtension( const std::string& json )
        : StanzaExtension( ExtUser + 1 ), m_json( json )
    {
    }

    JsonExtension::JsonExtension( const Tag* tag )
        : StanzaExtension( ExtUser + 1 ), m_json( "" )
    {
        if (!tag) {
            return;
        }
        m_json = tag->findAttribute( "json" );
    }

    JsonExtension::~JsonExtension()
    {
    }

    const std::string& JsonExtension::filterString() const
    {
        static const std::string filter = "/message/*[@xmlns='urn:xmpp:json:0']";
        return filter;
    }

    Tag* JsonExtension::tag() const {
        Tag* tag = new Tag( m_json, XMLNS, "urn:xmpp:json:0" );
        if ( !m_json.empty() ) {
            tag->addAttribute( "json", m_json );
        }
        return tag;
    }
}
