#ifndef SIGNAL_HANDLER_H
#define SIGNAL_HANDLER_H

#include <signal.h>
#include <ucontext.h>
       
class SaveSignals
{
	vector<struct sigaction> old_handlers;

public:
	SaveSignals(); /* save signals */
	~SaveSignals(); /* restore signals */
};

namespace SignalHandler
{
	typedef void (*handler)( int, siginfo_t *si, const ucontext_t *uc );

	void OnClose(handler);
};

#endif

/* Written by Glenn Maynard.  Public domain. */

