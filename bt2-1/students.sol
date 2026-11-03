//SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract StudentData{
    struct Student{
        uint id;
        string name;
        string course;
        uint marks;
        uint roll;
    }
    Student[] public students;
    
    event StudentAdded(uint id, string name, string course, uint marks, uint roll);
    function addStudent(string memory name, string memory course, uint marks, uint roll) public{
        uint newID= students.length+1;
        students.push(Student(newID, name, course, marks, roll));
        emit StudentAdded(newID, name, course, marks, roll);
    }
    function getStudent(uint index)public view returns(uint id, string memory name, string memory course, uint marks, uint roll){
        require(index<students.length, "Index out of bounds");
        Student memory s= students[index];
        return (s.id, s.name, s.course, s.marks, s.roll);
    }
    function getAllStudents()public view returns(Student[] memory){
        return students;
    }
    function getNumberOfStudents() public view returns(uint n){
        return students.length;
    }
    function getEth() public view returns(uint eth){
        return address(this).balance;
    }

}