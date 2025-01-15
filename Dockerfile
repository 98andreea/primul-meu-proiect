FROM gcc:latest
WORKDIR /usr/src/myapp
COPY main.c .
RUN gcc -Wall main.c -lm
CMD ["./a.out"]