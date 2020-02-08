FROM rikorose/gcc-cmake:gcc-7
 
# Copy the current folder which contains C++ source code to the Docker image under /usr/src
COPY . /usr/potato/
 
# Specify the working directory
WORKDIR /usr/potato

RUN apt-get update
RUN apt-get install -y vim nano tmux