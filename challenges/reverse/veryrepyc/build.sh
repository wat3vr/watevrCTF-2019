python3 -OO -m py_compile circ.py
mv __pycache__/circ.cpython-36.opt-2.pyc 3nohtyp.pyc
rm -R __pycache__/
chmod +x 3nohtyp.pyc
mv 3nohtyp.pyc downloads/
