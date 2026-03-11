var assert = require('assert');
var solution033 = require('../src/euler/solution033');

describe('Solution033', function() {
  describe('answer', function() {
    it('will answer problem 033', function() {
      assert.equal(solution033.answer(), 100);
    });
  });
});