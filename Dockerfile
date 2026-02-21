FROM gcc:13

WORKDIR /app
COPY . .

RUN g++ main.cpp -o thermometer

CMD ["./thermometer"]