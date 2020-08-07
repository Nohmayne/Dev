import React, { Component } from "react";
import TodoItems from "./TodoItems";
import "./TodoList.css";

class TodoList extends Component {
    constructor(props) {
        super(props);

        this.state = {
            items: []
        };
        this.addItem = this.addItem.bind(this);
    }

    // 0 == "0"
    // 0 !== "0"

    addItem(e) {
        if (this._inputElement.value !== "") {
            var newItem = {
                text: this._inputElement.value,
                key: Date.now()
            };

            this.setState((prevState) => {
                return {
                    items: prevState.items.concat(newItem)
                };
            });

            this._inputElement.value = "";

            e.preventDefault();
        }
    }

    render() {
        return (
            <div className="todoListMain">
                <div className="title">
                    <h1>List Title</h1>
                    <p>List description describing the list</p>
                </div>
                <div className="tags">
                </div>
                <div className="header">
                    <form onSubmit={this.addItem}>
                        <input ref={(a) => this._inputElement = a}
                            placeholder="Enter task">
                            </input>
                        <button type="submit">
                            <img src="add-icon.png" alt="Add" width="16" height="15">
                            </img>
                        </button>
                    </form>
                </div>
                <TodoItems entries={this.state.items}/>
            </div>
        );
    }
}

export default TodoList;
