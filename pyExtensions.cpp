#include <pybind11/pybind11.h>
#include <vector>
namespace py = pybind11;

int add(int i, int j)
{
	std::vector<size_t> vec{};
	vec.reserve(150000000);
	for (size_t i = 0; i < 150000000; i++)
	{
		i += i % (i - 2);
		vec.push_back(i);
	}
	printf("result: %lld\n\r", vec[1500]);
	return 0;
}

class PyExtension
{
public:
	PyExtension();
	~PyExtension();
	inline void classMemberCall() { printf(" Class call\n\r"); };

private:

};

PyExtension::PyExtension()
{
}

PyExtension::~PyExtension()
{
}


PYBIND11_MODULE(PythonExtension, m)
{
	// optional module doc string
	m.doc() = "pybind11 example plugin";
	// expose add function, and add keyword arguments and default arguments
	m.def("add", &add, "A function which adds two numbers");
	py::class_<PyExtension>(m, "PyExtension")
		.def(py::init())
		.def("classMemberCall", &PyExtension::classMemberCall);
	// exporting variables
	m.attr("the_answer") = 42;
	py::object world = py::cast("World");
	m.attr("what") = world;

}