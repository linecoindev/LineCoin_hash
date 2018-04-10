from distutils.core import setup, Extension

line_hash_module = Extension('line_hash',
                                 sources = ['linemodule.c',
                                            'line.c',
                                            'sha3/blake.c',
                                            'sha3/bmw.c',
                                            'sha3/groestl.c',
                                            'sha3/jh.c',
                                            'sha3/keccak.c',
                                            'sha3/skein.c',
                                            'sha3/cubehash.c',
                                            'sha3/echo.c',
                                            'sha3/luffa.c',
                                            'sha3/simd.c',
                                            'sha3/shavite.c'],
                               include_dirs=['.', './sha3'])

setup (name = 'line_hash',
       version = '1.3.1',
       description = 'Binding for LineCoin NeoScrypt proof of work hashing.',
       ext_modules = [line_hash_module])
