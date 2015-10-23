#include "Context_decl.h"
#ifndef INCLUDED_Context_h_GUID_DD0155F5_61A4_4A76_8C2E_D9614C7A9EBD
#define INCLUDED_Context_h_GUID_DD0155F5_61A4_4A76_8C2E_D9614C7A9EBD

// Internal Includes
#include <osvr/ClientKit/ContextC.h>
#include <osvr/ClientKit/ParametersC.h>
#include "Interface.h"
#include <osvr/Util/StringBufferBuilder.h>
#include "Handle.h"
// Library/third-party includes
// - none

// Standard includes
#include <string>
#include <stdexcept>

using osvr::clientkit
        
namespace osvr {

    namespace clientkit {
        ClientContext(const char applicationIdentifier[],
                                        uint32_t flags)
        : m_context(osvrClientInit(applicationIdentifier, flags)) {}

        ClientContext(OSVR_ClientContext context)
        : m_context(context) {}

        ~ClientContext() { osvrClientShutdown(m_context); }

    }
}
#endif // INCLUDED_Context_h_GUID_DD0155F5_61A4_4A76_8C2E_D9614C7A9EBD