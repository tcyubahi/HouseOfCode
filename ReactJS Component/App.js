import React, { Component } from 'react';
import './App.css';
import StarWarsPerson from './components/StarWarsPerson';

class App extends Component {
  constructor(props) {
    super(props);
    this.state = {
      starWarsPeople: []
    }
  }

  componentDidMount() {
    this.getPeople();
  }

  async getPeople () {
    await fetch("https://swapi.co/api/people/?format=json")
    .then(res => res.json())
    .then(
      (result) => {

      this.setState({
        starWarsPeople: result.results
      }, ()=> {
        console.log(this.state.starWarsPeople);
      });
    },
    (error) => {
      console.log(error);
    }
    )
  }

  render() {
    const { starWarsPeople } = this.state;
    return (
      <div className="App">
        <h2> Star Wars Characters </h2>
        {
          starWarsPeople.map((person) => 
            <StarWarsPerson key={person.name} name={person.name} height={person.height} birthYear={person.birth_year} gender={person.gender} />
          )
        }
      </div>
    );
  }
}

export default App;
