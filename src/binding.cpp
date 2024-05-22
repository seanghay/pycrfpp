#include <pybind11/pybind11.h>
#include "crfpp.h"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

PYBIND11_MODULE(pycrfpp, m)
{
  py::class_<CRFPP::Tagger>(m, "Tagger")
      .def(py::init([](std::string arg)
                    {
        CRFPP::Tagger *tagger = CRFPP::createTagger(arg.c_str());
        if (!tagger) {
          throw CRFPP::getLastError();
        }
        return std::unique_ptr<CRFPP::Tagger>(tagger); }))
      .def("clear", &CRFPP::Tagger::clear)
      .def("add", static_cast<bool (CRFPP::Tagger::*)(const char *)>(&CRFPP::Tagger::add))
      .def("parse", static_cast<bool (CRFPP::Tagger::*)()>(&CRFPP::Tagger::parse))
      .def("size", &CRFPP::Tagger::size)
      .def("ysize", &CRFPP::Tagger::ysize)
      .def("xsize", &CRFPP::Tagger::xsize)
      .def("y", &CRFPP::Tagger::y)
      .def("y2", &CRFPP::Tagger::y2)
      .def("x", static_cast<const char *(CRFPP::Tagger::*)(size_t, size_t) const>(&CRFPP::Tagger::x))
      .def("yname", &CRFPP::Tagger::yname)
      .def("answer", &CRFPP::Tagger::answer)
      .def("result", &CRFPP::Tagger::result)
      .def("alpha", &CRFPP::Tagger::alpha)
      .def("beta", &CRFPP::Tagger::beta)
      .def("best_cost", &CRFPP::Tagger::best_cost)
      .def("penalty", &CRFPP::Tagger::penalty)
      .def("set_penalty", &CRFPP::Tagger::set_penalty)
      .def("set_nbest", &CRFPP::Tagger::set_nbest)
      .def("prob", static_cast<double (CRFPP::Tagger::*)() const>(&CRFPP::Tagger::prob))
      .def("prob", static_cast<double (CRFPP::Tagger::*)(size_t) const>(&CRFPP::Tagger::prob))
      .def("prob", static_cast<double (CRFPP::Tagger::*)(size_t, size_t) const>(&CRFPP::Tagger::prob));

#ifdef VERSION_INFO
  m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
  m.attr("__version__") = "dev";
#endif
}