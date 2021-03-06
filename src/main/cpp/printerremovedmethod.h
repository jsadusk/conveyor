// vim:cindent:cino=\:0:et:fenc=utf-8:ff=unix:sw=4:ts=4:

#ifndef PRINTERREMOVEDMETHOD_H
#define PRINTERREMOVEDMETHOD_H (1)

#include <jsonrpc.h>

#include <conveyor/fwd.h>

namespace conveyor
{
    class PrinterRemovedMethod : public JsonRpcMethod
    {
    public:
        PrinterRemovedMethod (ConveyorPrivate * conveyorPrivate);
        ~PrinterRemovedMethod (void);
        
        Json::Value invoke (Json::Value const & params);
        
    private:
        ConveyorPrivate * const m_conveyorPrivate;
    };
}

#endif // PRINTERREMOVEDMETHOD_H
