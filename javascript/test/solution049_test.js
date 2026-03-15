var assert = require('assert');
var solution049 = require('../src/euler/solution049');

describe('Solution049', function() {
  describe('answer', function() {
    it('will answer problem 049', function() {
      assert.equal(solution049.answer(), 296962999629);
    });
  });
});