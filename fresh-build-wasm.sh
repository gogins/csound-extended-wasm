clear
echo "Fresh build of Csound for WebAssembly..."
bash update-dependency-submodules.sh
bash update-emscripten-wasm.sh
bash clean-build-wasm.sh
echo "Completed fresh build of Csound for WebAssembly."
echo
