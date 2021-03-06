// vim:cindent:cino=\:0:et:fenc=utf-8:ff=unix:sw=4:ts=4:

#ifndef CONVEYOR_JOB_H
#define CONVEYOR_JOB_H (1)

#include <QList>
#include <QObject>
#include <QScopedPointer>
#include <QString>

#include <conveyor/fwd.h>
#include <conveyor/jobstatus.h>

namespace conveyor
{
    class Job : public QObject
    {
        Q_OBJECT

    public:
        ~Job (void);

        int id (void) const;
        QString name (void) const;
        JobState state (void) const;
        JobConclusion conclusion (void) const;

        int currentStepProgress (void) const;
        QString currentStepName (void) const;

        void cancel (void);
        void pause (void);
        
    signals:
        void changed (const Job *);

    private:
        Job (Conveyor * conveyor, int const & id);

        QScopedPointer <JobPrivate> m_private;

        void emitChanged (void);

        friend class Conveyor;
        friend class ConveyorPrivate;
        friend class JobAddedMethod;
        friend class JobChangedMethod;
        friend class JobPrivate;
        friend class Printer;
        friend class PrinterPrivate;
    };
}

#endif
