#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {


public:
	virtual void update(String message) = 0;
};

#endif
