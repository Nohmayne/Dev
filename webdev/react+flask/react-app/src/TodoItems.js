import React, { Component } from "react";

class TodoItems extends Component {
    createTasks(item) {
        return (
            <li key={item.key}>
                <input type="checkbox" id="{item.key}" name="{item.key}" value="{item.text}"/>
                <label htmlFor="{item.key}"> {item.text}</label>
            </li>
        );
    }

    render() {
        var todoEntries = this.props.entries;
        var listItems = todoEntries.map(this.createTasks);

        return (
            <ul className="theList">
                {listItems}
            </ul>
        );
    }
}

export default TodoItems;
