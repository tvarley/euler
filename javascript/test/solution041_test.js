var assert = require('assert');
var solution041 = require('../src/euler/solution041');

describe('Solution041', function() {
  describe('answer', function() {
    it('will answer problem 041', function() {
      assert.equal(solution041.answer(), 7652413);
    });
  });
});