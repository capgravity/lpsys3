// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract BankAccount {

    // Mapping to store balance of each customer address
    mapping(address => uint256) private balances;

    // Events
    event Deposited(address indexed customer, uint256 amount);
    event Withdrawn(address indexed customer, uint256 amount);

    // 1. Deposit Money
    function deposit() public payable {
        require(msg.value > 0, "Deposit amount must be greater than 0");
        balances[msg.sender] += msg.value;
        emit Deposited(msg.sender, msg.value);
    }

    // 2. Withdraw Money
    function withdraw(uint256 amount) public {
        require(amount > 0, "Withdraw amount must be greater than 0");
        require(balances[msg.sender] >= amount, "Insufficient balance");

        balances[msg.sender] -= amount;
        (bool success, ) = payable(msg.sender).call{value:amount}("");
        require(success, "Transfer failed");
        emit Withdrawn(msg.sender, amount);
    }

    // 3. Show Balance
    function showBalance() public view returns (uint256) {
        return balances[msg.sender];
    }
}