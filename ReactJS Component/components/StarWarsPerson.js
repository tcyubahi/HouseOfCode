import React, { Component } from 'react';
import PropTypes from "prop-types";

class StarWarsPerson extends Component {

  render() {
    
    const { name, height, birthYear, gender } = this.props;

    return (
      <div className="card">
          <div className="name">{name}</div>
          <div className="height"><small>Height:</small> <strong>{height}</strong></div>
          <div className="birthYear"><small>YOB:</small> <strong>{birthYear}</strong></div>
          <div className="Gender"><small>Gender:</small> <strong>{gender}</strong></div>
      </div>
    );
  }
}

StarWarsPerson.propTypes = {
  name: PropTypes.string.isRequired,
  height: PropTypes.string.isRequired,
  birthYear: PropTypes.string.isRequired,
  gender: PropTypes.oneOf(['male', 'female', 'n/a']).isRequired,
}

export default StarWarsPerson;
