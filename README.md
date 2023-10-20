# Instrucitons for reproducing the bug

```
python3.10 -m venv .venv
source .venv/bin/activate
python configure.py
pip install -r requirements.txt
bazel run -c dbg //courier:debug_client_test
```
