var assert = require('assert');
var solution010 = require('../src/euler/solution010');

describe('Solution010', function() {
  describe('answer', function() {
    it('will answer problem 010', function() {
      assert.equal(solution010.answer(), 142913828922);
    });
  });
});