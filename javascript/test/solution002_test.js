var assert = require('assert');
var solution002 = require('../src/euler/solution002');

describe('Solution002', function() {
  describe('answer', function() {
    it('will answer problem 002', function() {
      assert.equal(solution002.answer(), 4613732);
    });
  });
});
