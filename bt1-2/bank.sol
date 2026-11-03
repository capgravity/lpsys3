//SPDX-License-Identifier: MIT

pragma solidity ^0.8.0;

contract BankAccount{
    mapping(address customer => uint256 balance) private balances;
    event Withdrawn(address indexed customer, uint balance);
    event Deposited(address indexed customer, uint balance);

    function deposit() public payable{
        require(msg.value>0, "Value to deposited needs to be greater than 0");
        balances[msg.sender]+=msg.value;
        emit Deposited(msg.sender, msg.value);
    }

    function withdraw(uint amount)public {
        require(amount>0, "Value to be withdrawn should be greater than 0");
        require(amount<=balances[msg.sender], "Value to be withdrawn is greater than value in bank");
        balances[msg.sender]-= amount;
        (bool success, )=payable(msg.sender).call{value: amount}("");
        require(success, "TX failed");
        emit Withdrawn(msg.sender, amount);
    }

    function getBalance() public view returns(uint){
        return balances[msg.sender];
    }
}
