var assert = require('assert');
var solution003 = require('../src/euler/solution003');

describe('Solution003', function() {
  describe('answer', function() {
    it('will answer problem 003', function() {
      assert.equal(solution003.answer(), 6857);
    });
  });
});
