var assert = require('assert');
var solution011 = require('../src/euler/solution011');

describe('Solution011', function() {
  describe('answer', function() {
    it('will answer problem 011', function() {
      assert.equal(solution011.answer(), 70600674);
    });
  });
});