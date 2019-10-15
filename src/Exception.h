#pragma once

#include <stdexcept>

class PotatoException : public std::runtime_error {
  public:
    PotatoException(const std::string &error = "Potato Base Exception")
        : std::runtime_error(error)
    {
    }
};

class BadRequest : public PotatoException {
  public:
    BadRequest()
        : PotatoException("Bad HTTP Request")
    {
    }
};

class InvalidRequestMethod : public BadRequest {
  public:
    InvalidRequestMethod()
        : BadRequest()
    {
    }
};