var assert = require('assert');
var solution079 = require('../src/euler/solution079');

describe('Solution079', function() {
  describe('answer', function() {
    it('will answer problem 079', function() {
      assert.equal(solution079.answer(), '73162890');
    });
  });
});