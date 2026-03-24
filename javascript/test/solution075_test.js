var assert = require('assert');
var solution075 = require('../src/euler/solution075');

describe('Solution075', function() {
  describe('answer', function() {
    it('will answer problem 075', function() {
      assert.equal(solution075.answer(), 161667);
    });
  });
});