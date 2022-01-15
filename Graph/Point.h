#include <unordered_set>

class Vertex {

	//Connections
	std::unordered_set<Vertex*> conns;

public:
	double x = 0;
	double y = 0;
	//Consider templating class to allow
	//for vertices in N-dimensional spaces
	//now THATD be a challenge!

	//consider removing non-pointer functions
	void connect(Vertex* const v);
	void connect(Vertex& v);

	void disconnect(Vertex* const v);
	void disconnect(Vertex& v);

	auto getConnections() const& { return conns; }
	bool isConnected(Vertex* const v) { return conns.find(v) != conns.end(); }

	int getDegree() const { return conns.size(); }
};