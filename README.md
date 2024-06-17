# conda_torch_extension (CTE)
This is a small test repo to use conda to compile CPP and CUDA extnesions for pytorch

# Install CTE
This is the procedure to set up compiled test extensions written in c++/CUDA.

This is eht end-users would do to enable the exension(s) for their own use.

## Linux

If you're installing from scratch and don't have an environment yet, here is the easiest way to get everything inside a new environment called `cte`:
```
conda create -n cte cte -c ctec -c nvidia/label/cuda-11.7.0 -c pytorch -c conda-forge
conda activate cte  
```

If you want to install in an already existing environment:
```
conda install cte -c ctec -c nvidia/label/cuda-11.7.0 -c pytorch -c conda-forge
```

If you want to update to the latest version and already have all channels set up in your environment:
```
conda update cte
```

# Build CTE on Linux

This is the procedure to compile the cte exstension(s) from c++/CUDA code
After cloning this repository, run these commands:
```
conda env create -f cte_build.yml
conda activate cte_build
./scripts/build_unix.sh
```
All binaries will be in `Release/linux-x64/publish`.
