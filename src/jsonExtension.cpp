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
        m_json = tag->cdata( );
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
        Tag* tag = new Tag( "json");
        tag->setXmlns("urn:xmpp:json:0");
        tag->setCData(m_json);
        return tag;
    }
}
