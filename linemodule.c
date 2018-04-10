#include <Python.h>

#include "line.h"

static PyObject *line_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    line_hash((char *)PyBytes_AsString((PyObject*) input), (int)PyBytes_Size((PyObject*) input), output);
#else
    line_hash((char *)PyString_AsString((PyObject*) input), (int)PyString_Size((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef LineCoinMethods[] = {
    { "getPoWHash", line_getpowhash, METH_VARARGS, "Returns the proof of work hash using line hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef LineCoinModule = {
    PyModuleDef_HEAD_INIT,
    "line_hash",
    "...",
    -1,
    LineCoinMethods
};

PyMODINIT_FUNC PyInit_line_hash(void) {
    return PyModule_Create(&LineCoinModule);
}

#else

PyMODINIT_FUNC initline_hash(void) {
    (void) Py_InitModule("line_hash", LineCoinMethods);
}
#endif
